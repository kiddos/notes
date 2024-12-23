import ollama

response = ollama.chat(
    model='llama3.2-vision',
    messages=[
        {
            'role': 'user',
            'content': 'what is in the image?',
            'images': ['robot.png'],
        }
    ]
)

print(response)
