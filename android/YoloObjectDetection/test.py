import numpy as np
import cv2
import tensorflow as tf

# 1. Load the TFLite model and allocate tensors.
model_path = "yolo11n_saved_model/yolo11n_float32.tflite"
interpreter = tf.lite.Interpreter(model_path=model_path)
interpreter.allocate_tensors()

# Get input and output details
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()
input_shape = input_details[0]['shape']  # [1, 640, 640, 3]

# 2. Prepare the Image
image_path = "test_images/3.jpg"
original_img = cv2.imread(image_path)
h_orig, w_orig = original_img.shape[:2]

# Resize and Normalize (Match your Android ImageProcessor)
img = cv2.resize(original_img, (input_shape[1], input_shape[2]))
img = img.astype(np.float32) / 255.0  # Normalize to [0, 1]
img = np.expand_dims(img, axis=0)  # Add batch dimension [1, 640, 640, 3]

# 3. Run Inference
interpreter.set_tensor(input_details[0]['index'], img)
interpreter.invoke()

# 4. Get Output [1, 300, 6]
output_data = interpreter.get_tensor(output_details[0]['index'])[0]

# 5. Parse and Draw
for i in range(300):
    # Extract [x1, y1, x2, y2, score, class_id]
    x1, y1, x2, y2, score, class_id = output_data[i]
    print(output_data[i])

    if score > 0.5:  # Confidence threshold
        # IMPORTANT: Check if output is normalized (0-1) or absolute (0-640)
        # If the boxes are tiny, they are likely 0-1 and need multiplying by input size
        # Most YOLOv8 TFLite exports return absolute coordinates (0-640)

        # Scale back to original image size for display
        # Here we assume the model output is in the 0..640 range
        scale_w = input_shape[1]
        scale_h = input_shape[2]

        box_x1 = int(x1 * scale_w)
        box_y1 = int(y1 * scale_h)
        box_x2 = int(x2 * scale_w)
        box_y2 = int(y2 * scale_h)

        # Draw Box
        cv2.rectangle(original_img, (box_x1, box_y1), (box_x2, box_y2),
                      (0, 255, 0), 2)
        cv2.putText(original_img, f"ID:{int(class_id)} {score:.2f}",
                    (box_x1, box_y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                    (0, 255, 0), 2)

cv2.imshow("YOLOv8 TFLite Detection", img[0])
cv2.waitKey(0)
cv2.destroyAllWindows()
