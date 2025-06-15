```sh
git clone --depth=1 https://github.com/fishaudio/fish-speech
cd fish-speech
pip install -e .
pip install torchvision # fix segmentation fault when import pytorch_lightening
```

create fake.npy

```sh
python fish_speech/models/dac/inference.py \
    -i "ref_audio_name.wav" \
    --checkpoint-path "checkpoints/openaudio-s1-mini/codec.pth"
```

generate audio

```sh
python fish_speech/models/text2semantic/inference.py \
    --text "The text you want to convert" \
    --prompt-text "Your reference text" \
    --prompt-tokens "fake.npy" \
    --compile
```
