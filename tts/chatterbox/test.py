import torchaudio as ta
from chatterbox.tts import ChatterboxTTS

device = 'cuda'
# device = 'cpu'
model = ChatterboxTTS.from_pretrained(device=device)

# text = "Ezreal and Jinx teamed up with Ahri, Yasuo, and Teemo to take down the enemy's Nexus in an epic late-game pentakill."
text = "Morty, listen, you can’t just quantize your emotional dependency on a linear timeline! That’s not how multiversal entropy works, Morty! God, it’s like talking to a sentient toaster strudel. Pass me the dark matter vodka—I need to forget I invented feelings"
# wav = model.generate(text)
# ta.save("test-1.wav", wav, model.sr)

# If you want to synthesize with a different voice, specify the audio prompt
AUDIO_PROMPT_PATH = "male_rickmorty.mp3"
wav = model.generate(
    text,
    audio_prompt_path=AUDIO_PROMPT_PATH,
    exaggeration=0.9,
    cfg_weight=0.5,
)
ta.save("test-2.wav", wav, model.sr)
