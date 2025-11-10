import module
from module import LFU

print(module.get_memory_info())
cache = LFU(30)
for i in range(100):
    cache.put(f'key{i}', f'value{i}')

for i in range(100):
    val = cache.get(f'key{i}')
    if val:
        print(val)
