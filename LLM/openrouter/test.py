import os
from openai import OpenAI

API_KEY = os.getenv('OPENROUTER_API_KEY')

client = OpenAI(
    base_url="https://openrouter.ai/api/v1",
    api_key=API_KEY,
)

response = client.chat.completions.create(
    # model="openai/gpt-oss-120b:free",
    model="nvidia/nemotron-3.5-content-safety:free",
    messages=[{
        "role": "user",
        "content": "How many r's are in the word 'strawberry'?"
    }],
    extra_body={"reasoning": {
        "enabled": True
    }})

# Extract the assistant message with reasoning_details
response = response.choices[0].message
content = response.content
print(response.reasoning)
print(content)
