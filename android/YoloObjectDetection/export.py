from ultralytics import YOLO


def main():
    model = YOLO("yolo11n.pt")
    model.export(format="tflite", imgsz=(640, 640), nms=True)


if __name__ == '__main__':
    main()
