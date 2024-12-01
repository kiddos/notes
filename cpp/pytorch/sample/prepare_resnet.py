import torch
import torchvision

model = torchvision.models.resnet50(pretrained=True)
model.eval()

example = torch.randn(1, 3, 224, 224)

traced_script_module = torch.jit.trace(model, example)
traced_script_module.save("traced_resnet_model.pt")
