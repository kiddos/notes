import requests
import json

url = 'http://localhost:11434/api/generate'
data = {
    'model': 'llama3.2:1b',
    'prompt': 'Tell me a story',
    'stream': False,
    'options': {
        'top_k': 20,
        'top_p': 0.95,
    }
}
response = requests.post(url, json.dumps(data))
result = json.loads(response.content.decode('utf-8'))
print(json.dumps(result, indent=2, sort_keys=True))
