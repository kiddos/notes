from datetime import datetime
import json
import requests
from playsound import playsound


def list_voice():
    url = 'http://localhost:8880/v1/audio/voices'
    response = requests.get(url)
    content = response.content.decode('utf-8')
    data = json.loads(content)
    print(data)


def get_speech(message, voice):
    data = {
        'model': 'kokoro',
        'input': message,
        'voice': voice
    }
    response = requests.post('http://localhost:8880/v1/audio/speech', json=data)
    # use current date as filename
    today = datetime.now()
    filename = today.strftime("%Y-%m-%d") + '.wav'
    with open(filename, 'wb') as f:
        f.write(response.content)
    playsound(filename)


def main():
    list_voice()
#     voice = 'zm_yunyang'
#     # voice = 'zf_xiaoni'
#     message = """
# 夏暮思情
#
# 蝉声渐歇柳风轻，
# 池畔微波映落晴。
# 旧梦如烟随暮色，
# 心头一念到君行。
#
# 荷香暗送南窗静，
# 斜照残阳映鬓青。
# 倘若有情终不晚，
# 天涯何处不相迎。
#     """

    # voice = 'am_liam'
    # voice = 'bf_lily'
#     voice = 'am_santa'
#     message = """
# Ho ho ho! Merry Christmas, my dear!
# You've been on my Nice List all year!
# Remember, it’s not the gifts that make Christmas bright,
# It’s kindness, love, and hearts full of light!
# So hang up your stocking, and snug into bed—
# For magical dreams are just up ahead!
#     """
    voice = 'bm_daniel'
    message = """
Very good, sir. I’ve taken the liberty of preparing your usual—tea at precisely ninety-two degrees, with a hint of bergamot, as you prefer.
Shall I also inform the chef that you’ll be dining alone this evening, or shall I set an extra place for the unexpected drama that so often accompanies your affairs?
    """

    get_speech(message, voice)


if __name__ == '__main__':
    main()
