import tensorflow as tf
from tensorflow import keras

model = tf.keras.applications.EfficientNetB5(input_shape=(456, 456, 3), weights='imagenet')

static_input = keras.layers.Input(shape=(456, 456, 3), batch_size=1, name='input_tensor')
model_with_static_batch = keras.Model(inputs=static_input, outputs=model(static_input))

converter = tf.lite.TFLiteConverter.from_keras_model(model_with_static_batch)
converter.optimizations = [tf.lite.Optimize.DEFAULT]
tflite_model = converter.convert()

with open('efficientnet-b5.tflite', "wb") as f:
    f.write(tflite_model)
