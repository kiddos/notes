import torch
import torchaudio
from zonos.model import Zonos
from zonos.conditioning import make_cond_dict
from zonos.utils import DEFAULT_DEVICE as device
import time
import gc

# model = Zonos.from_pretrained("Zyphra/Zonos-v0.1-transformer", device=device)
model = Zonos.from_pretrained("Zyphra/Zonos-v0.1-transformer", device='cpu')

wav, sampling_rate = torchaudio.load("sample.mp3")
speaker = model.make_speaker_embedding(wav, sampling_rate)

cond_dict = make_cond_dict(
    text="Hello there, I'm Rick from the Rick and Morty show. Fuck you moron. Fuck.",
    speaker=speaker,
    language="en-us",
    device='cpu'
)
conditioning = model.prepare_conditioning(cond_dict)

codes = model.generate(conditioning)

wavs = model.autoencoder.decode(codes).cpu()
torchaudio.save("output.wav", wavs[0], model.autoencoder.sampling_rate)

torch.cuda.empty_cache()
gc.collect()

while True:
    time.sleep(1)
