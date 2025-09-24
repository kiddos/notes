- download videos

```sh
ffmpeg -i http://<url>.m3u8 -c copy "output.mp4"
```

- record screen

```sh
ffmpeg -f x11grab -framerate 25 -r 25 -s 1920x1080 -i :0.0 output.mp4
```

- build from source

[link](https://trac.ffmpeg.org/wiki/CompilationGuide/Ubuntu)
[source](https://git.ffmpeg.org/ffmpeg.git)

1. install nv-code-headers

```sh
git clone https://git.videolan.org/git/ffmpeg/nv-codec-headers.git
```

2. install Video Codec SDK

```sh
cp Interface/*.h /usr/local/cuda/include 
cp Lib/linux/stubs/x86_64/* /usr/local/cuda/targets/x86_64-linux/lib/
```

3. build ffmpeg

```sh
git clone https://git.ffmpeg.org/ffmpeg.git
cd ffmpeg
git checkout release/5.1
./configure --prefix=$HOME/.local --enable-nonfree --enable-nvenc  --enable-libnpp --enable-cuda-nvcc --nvccflags="-gencode arch=compute_75,code=sm_75 -O2" --extra-cflags=-I/usr/local/cuda/include  --extra-ldflags=-L/usr/local/cuda/lib64
```
