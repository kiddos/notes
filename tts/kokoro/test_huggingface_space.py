from gradio_client import Client, handle_file

# Connect to a public Space
client = Client("k2-fsa/OmniVoice")
# print(client.view_api())

text = """Honey, are you still at your desk? I feel like I’ve seen the back of your head more than your face today.

I know, I know—the ‘sparky’ project is at a critical stage and that memory leak isn’t going to fix itself. But seriously, if I hear one more deep sigh followed by the sound of furious typing, I’m going to start charging that Neovim setup rent. You get that specific look in your eyes, like you're physically here in the room but your brain is actually lost somewhere inside a stack trace.

I made some tea—it’s on the coaster, don’t let it get cold. And please, for the love of everything, don't tell me you're 'almost done' if that actually means another three hours of debugging. The screen isn't going anywhere, but your back is going to be permanently shaped like that office chair if you don't stretch."""

lang = 'English'
ns = 32
gs = 2.0
dn = True
sp = 1.0
du = 0
pp = True
po = True
param_9 = 'Female / 女'
param_10 = 'Young Adult / 青年'
param_11 = 'Auto'
param_12 = 'Auto'
param_13 = 'American Accent / 美式口音'
param_14 = 'Auto'

result = client.predict(
    text=text,
    lang=lang,
    ns=ns,
    dn=dn,
    sp=sp,
    du=du,
    pp=pp,
    po=po,
    param_9=param_9,
    param_10=param_10,
    param_11=param_11,
    param_12=param_12,
    param_13=param_13,
    param_14=param_14,
    api_name="/_design_fn",
)
print(result)
