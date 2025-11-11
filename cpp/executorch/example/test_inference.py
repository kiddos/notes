import torch
import torchvision.transforms as transforms
from executorch.runtime import Runtime
from PIL import Image
import json


def resize_image(image: Image.Image, size: int) -> Image:
    width, height = image.size
    max_dim = max(width, height)
    padded_image = Image.new('RGB', (max_dim, max_dim), (0, 0, 0))
    x_offset = (max_dim - width) // 2
    y_offset = (max_dim - height) // 2
    padded_image.paste(image, (x_offset, y_offset))
    resized_image = padded_image.resize((size, size), Image.LANCZOS)
    return resized_image


image_path = "./test.jpeg"
img = Image.open(image_path)
img = resize_image(img, 224)
img.save('./test.png')

runtime = Runtime.get()
to_tensor = transforms.ToTensor()
tensor_image = to_tensor(img)
tensor_image = tensor_image.reshape([1, 3, 224, 224])

program = runtime.load_program("mobilenet_v2.pte")
method = program.load_method("forward")
output = method.execute([tensor_image])
with open('imagenet_labels.json', 'r') as f:
    labels = json.load(f)

print("Run succesfully via executorch")
idx = torch.argmax(output[0], dim=1)
idx = str(idx.item())
print(labels[idx])
