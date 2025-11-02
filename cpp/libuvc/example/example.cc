#include <libuvc/libuvc.h>
#include <unistd.h>

#include <iostream>

static volatile int keep_running = 1;
static volatile int frame_captured = 0;

void capture_callback(uvc_frame_t *frame, void *ptr);

int main(void) {
  uvc_context_t* ctx = nullptr;
  uvc_error_t res = uvc_init(&ctx, nullptr);
  if (res < 0) {
    std::cerr << "Error: uvc_init failed: " << uvc_strerror(res) << std::endl;
    return 1;
  }

  uvc_device_t* dev = nullptr;
  res = uvc_find_device(ctx, &dev, 0, 0, NULL);
  if (res < 0) {
    std::cerr << "Error: No UVC device found: " << uvc_strerror(res)
              << std::endl;
    uvc_exit(ctx);
    return 1;
  }

  uvc_device_handle_t* devh = nullptr;
  res = uvc_open(dev, &devh);
  if (res < 0) {
    std::cerr << "Error: uvc_open failed:" << uvc_strerror(res) << std::endl;
    uvc_unref_device(dev);
    uvc_exit(ctx);
    return 1;
  }

  std::cout << "device opened." << std::endl;

  uvc_stream_ctrl_t ctrl;
  res = uvc_get_stream_ctrl_format_size(devh, &ctrl, UVC_FRAME_FORMAT_YUYV, 640, 480, 30);
  // res = uvc_get_stream_ctrl_format_size(devh, &ctrl, UVC_FRAME_FORMAT_MJPEG, 640, 480, 30);
  // res = uvc_get_stream_ctrl_format_size(devh, &ctrl, UVC_FRAME_FORMAT_H264, 640, 480, 30);
  if (res < 0) {
    res = uvc_get_stream_ctrl_format_size(devh, &ctrl, UVC_FRAME_FORMAT_ANY, 0, 0, 0);
    if (res < 0) {
      std::cerr << "Error: Failed to negotiate a streaming profile: " << uvc_strerror(res) << std::endl;;
      goto cleanup;
    }
  }

  res = uvc_start_streaming(devh, &ctrl, capture_callback, nullptr, 0);
  if (res < 0) {
    fprintf(stderr, "Error: uvc_start_streaming failed: %s\n", uvc_strerror(res));
    goto cleanup;
  }

  while (keep_running) {
    usleep(10000); // Sleep for 10ms
  }

cleanup:
  // uvc_stop_streaming(devh);
  uvc_close(devh);
  uvc_unref_device(dev);
  uvc_exit(ctx);
  std::cout << "cleanup..." << std::endl;
  return 0;
}

void capture_callback(uvc_frame_t *frame, void *) {
  uvc_frame_t *rgb = nullptr;

  if (frame_captured) {
    return;
  }

  rgb = uvc_allocate_frame(frame->width * frame->height * 3);
  if (!rgb) {
    std::cout << "Error: Unable to allocate RGB frame buffer!" << std::endl;
    return;
  }

  uvc_error_t ret = uvc_any2rgb(frame, rgb);
  if (ret) {
    std::cout << "Error: Failed to convert frame to RGB: " << uvc_strerror(ret) << std::endl;
    uvc_free_frame(rgb);
    return;
  }

  switch (frame->frame_format) {
  case UVC_FRAME_FORMAT_H264:
    std::cout << "h264" << std::endl;
    break;
  case UVC_COLOR_FORMAT_MJPEG:
    std::cout << "mjpeg" << std::endl;
    break;
  case UVC_COLOR_FORMAT_YUYV:
    std::cout << "yuyv" << std::endl;
    break;
  default:
    break;
  }

  uvc_free_frame(rgb);
  frame_captured = 1;
  keep_running = 0;
}
