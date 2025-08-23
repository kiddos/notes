import 'dart:ui' as ui;

import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:flutter/widgets.dart';

typedef AnimatedSamplerBuilder = void Function(ui.Image, Size, ui.Canvas);

class AnimatedSampler extends StatelessWidget {
  const AnimatedSampler({
    super.key,
    required this.builder,
    this.enabled = true,
    required this.child,
  });

  final AnimatedSamplerBuilder builder;
  final bool enabled;
  final Widget child;

  @override
  Widget build(BuildContext context) {
    return _ShaderSamplerBuilder(
      builder,
      enabled: enabled,
      child: child,
    );
  }
}

class _ShaderSamplerBuilder extends SingleChildRenderObjectWidget {
  const _ShaderSamplerBuilder(
    this.builder, {
    super.child,
    required this.enabled,
  });

  final AnimatedSamplerBuilder builder;
  final bool enabled;

  @override
  RenderObject createRenderObject(BuildContext context) {
    return _RenderShaderSamplerBuilderWidget(
      devicePixelRatio: MediaQuery.of(context).devicePixelRatio,
      builder: builder,
      enabled: enabled,
    );
  }

  @override
  void updateRenderObject(
      BuildContext context, covariant RenderObject renderObject) {
    (renderObject as _RenderShaderSamplerBuilderWidget)
      ..devicePixelRatio = MediaQuery.of(context).devicePixelRatio
      ..builder = builder
      ..enabled = enabled;
  }
}

class _RenderShaderSamplerBuilderWidget extends RenderProxyBox {
  _RenderShaderSamplerBuilderWidget({
    required double devicePixelRatio,
    required AnimatedSamplerBuilder builder,
    required bool enabled,
  })  : _devicePixelRatio = devicePixelRatio,
        _builder = builder,
        _enabled = enabled;

  @override
  OffsetLayer updateCompositedLayer(
      {required covariant _ShaderSamplerBuilderLayer? oldLayer}) {
    final _ShaderSamplerBuilderLayer layer =
        oldLayer ?? _ShaderSamplerBuilderLayer(builder);
    layer
      ..callback = builder
      ..size = size
      ..devicePixelRatio = devicePixelRatio;
    return layer;
  }

  double get devicePixelRatio => _devicePixelRatio;
  double _devicePixelRatio;
  set devicePixelRatio(double value) {
    if (value == _devicePixelRatio) {
      return;
    }

    _devicePixelRatio = value;
    markNeedsCompositedLayerUpdate();
  }

  AnimatedSamplerBuilder get builder => _builder;
  AnimatedSamplerBuilder _builder;
  set builder(AnimatedSamplerBuilder value) {
    if (value == _builder) {
      return;
    }

    _builder = value;
    markNeedsCompositedLayerUpdate();
  }

  bool get enabled => _enabled;
  bool _enabled;
  set enabled(bool value) {
    if (value == _enabled) {
      return;
    }

    _enabled = value;
    markNeedsPaint();
    markNeedsCompositedLayerUpdate();
  }

  @override
  bool get isRepaintBoundary => alwaysNeedsCompositing;

  @override
  bool get alwaysNeedsCompositing => enabled;

  @override
  void paint(PaintingContext context, Offset offset) {
    if (size.isEmpty || !_enabled) {
      return;
    }

    assert(offset == Offset.zero);
    return super.paint(context, offset);
  }
}

class _ShaderSamplerBuilderLayer extends OffsetLayer {
  _ShaderSamplerBuilderLayer(this._callback);

  Size get size => _size;
  Size _size = Size.zero;

  set size(Size value) {
    if (value == size) {
      return;
    }

    _size = value;
    markNeedsAddToScene();
  }

  double get devicePixelRatio => _devicePixelRatio;
  double _devicePixelRatio = 1.0;
  set devicePixelRatio(double value) {
    if (value == _devicePixelRatio) {
      return;
    }
    _devicePixelRatio = value;
    markNeedsAddToScene();
  }

  AnimatedSamplerBuilder get callback => _callback;
  AnimatedSamplerBuilder _callback;
  set callback(AnimatedSamplerBuilder value) {
    if (value == _callback) {
      return;
    }

    _callback = value;
    markNeedsAddToScene();
  }

  ui.Image _buildChildScene(Rect bounds, double pixelRatio) {
    final ui.SceneBuilder builder = ui.SceneBuilder();
    final Matrix4 transform =
        Matrix4.diagonal3Values(pixelRatio, pixelRatio, 1);
    builder.pushTransform(transform.storage);
    addChildrenToScene(builder);
    builder.pop();
    return builder.build().toImageSync((pixelRatio * bounds.width).ceil(),
        (pixelRatio * bounds.height).ceil());
  }

  @override
  void addToScene(ui.SceneBuilder builder) {
    if (size.isEmpty) {
      return;
    }

    final ui.Image image = _buildChildScene(offset & size, devicePixelRatio);
    final ui.PictureRecorder pictureRecorder = ui.PictureRecorder();
    final Canvas canvas = Canvas(pictureRecorder);
    try {
      callback(image, size, canvas);
    } finally {
      image.dispose();
    }
    final ui.Picture picture = pictureRecorder.endRecording();
    builder.addPicture(offset, picture);
  }
}
