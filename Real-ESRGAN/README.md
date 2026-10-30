# Real-ESRGAN (portable ncnn-vulkan build) notes

Image / video upscaling (super-resolution) tool. This folder uses the official
**portable Linux executable** `realesrgan-ncnn-vulkan-20220424-ubuntu.zip`
(Release v0.2.5.0). No CUDA or PyTorch needed — just unzip and run
(a GPU with Vulkan support is still required).

- GitHub: https://github.com/xinntao/Real-ESRGAN/
- Paper: https://arxiv.org/abs/2107.10833

## Setup

```shell
# Option 1: download the zip with the script
./download.sh

# Option 2: download manually
wget https://github.com/xinntao/Real-ESRGAN/releases/download/v0.2.5.0/realesrgan-ncnn-vulkan-20220424-ubuntu.zip

# Unzip and make the executable runnable
unzip realesrgan-ncnn-vulkan-20220424-ubuntu.zip
chmod u+x realesrgan-ncnn-vulkan
```

Requirements:

- A GPU that supports Vulkan (the executable is based on [Tencent/ncnn](https://github.com/Tencent/ncnn)).
- `ffmpeg` for the video workflow.

## Bundled models

The `models/` folder inside the zip contains:

| Model (`-n`) | Scale | Best for | Notes |
| --- | --- | --- | --- |
| `realesr-animevideov3` | 2 / 3 / 4 | anime, video frames | **default model**, fastest |
| `realesrgan-x4plus` | 4 | general photos, real-world images | best quality, slower |
| `realesrgan-x4plus-anime` | 4 | anime images | |
| `realesrnet-x4plus` | 4 | general photos | supported by the binary, but the model files are **not** in the zip — download manually into `models/` |

## Common commands

### Single image

```shell
# Simplest usage (default model realesr-animevideov3, 4x upscale)
./realesrgan-ncnn-vulkan -i input.jpg -o output.png

# Choose a specific model
./realesrgan-ncnn-vulkan -i input.jpg -o output.png -n realesr-animevideov3

# For general photos, prefer realesrgan-x4plus
./realesrgan-ncnn-vulkan -i input.jpg -o output.png -n realesrgan-x4plus
```

### Whole folder

```shell
# Output as jpg, 2x upscale (create the output folder first)
./realesrgan-ncnn-vulkan -i input_folder -o outputfolder -n realesr-animevideov3 -s 2 -f jpg

# 4x upscale
./realesrgan-ncnn-vulkan -i input_folder -o outputfolder -n realesr-animevideov3 -s 4 -f jpg
```

### Video (extract frames -> upscale -> merge back)

1. Use ffmpeg to extract frames from a video (remember to create the folder `tmp_frames` ahead)

```shell
ffmpeg -i onepiece_demo.mp4 -qscale:v 1 -qmin 1 -qmax 1 -vsync 0 tmp_frames/frame%08d.jpg
```

2. Run Real-ESRGAN on all frames (remember to create the folder `out_frames` ahead)

```shell
./realesrgan-ncnn-vulkan -i tmp_frames -o out_frames -n realesr-animevideov3 -s 2 -f jpg
```

3. Merge the enhanced frames back into a video and keep the original audio track

```shell
ffmpeg -i out_frames/frame%08d.jpg -i onepiece_demo.mp4 -map 0:v:0 -map 1:a:0 -c:a copy -c:v libx264 -r 23.98 -pix_fmt yuv420p output_w_audio.mp4
```

Note: `-r 23.98` is the frame rate from the original example. Replace it with the
frame rate of your own video (for example `24` or `30`). You can check it with
`ffprobe -v error -select_streams v -show_entries stream=r_frame_rate -of csv=p=0 yourvideo`.

## Full options

```
Usage: realesrgan-ncnn-vulkan -i infile -o outfile [options]...

  -h                   show this help
  -i input-path        input image path (jpg/png/webp) or directory
  -o output-path       output image path (jpg/png/webp) or directory
  -s scale             upscale ratio (can be 2, 3, 4. default=4)
  -t tile-size         tile size (>=32/0=auto, default=0) can be 0,0,0 for multi-gpu
  -m model-path        folder path to the pre-trained models. default=models
  -n model-name        model name (default=realesr-animevideov3, can be realesr-animevideov3 | realesrgan-x4plus | realesrgan-x4plus-anime | realesrnet-x4plus)
  -g gpu-id            gpu device to use (default=auto) can be 0,1,2 for multi-gpu
  -j load:proc:save    thread count for load/proc/save (default=1:2:2) can be 1:2,2,2:2 for multi-gpu
  -x                   enable tta mode
  -f format            output image format (jpg/png/webp, default=ext/png)
  -v                   verbose output
```

Tips:

- `-s` accepts 2, 3, or 4; the `realesrgan-x4plus` models support 4x only.
- If you run out of memory, reduce the tile size with `-t 64` (or smaller); `-t 0` means auto.
- `-x` enables TTA mode: slightly better quality, about 8x slower.
- Multi-GPU: `-g 0,1` with `-j 1:2,2,2:2` and `-t 0,0,0`.

## Known limitations

- The executable crops the input into tiles, processes them separately and
  stitches the results back together, so **block inconsistency** may appear and
  results differ slightly from the PyTorch implementation.
- Output files with the same name are overwritten; output folders are not
  created automatically — make them first.
- `.gitignore` excludes `*.jpg`, `*.png`, `*.mp4`, `models/` and the executable
  itself, so only the README and `download.sh` are tracked in this folder.

> The executable is derived from [nihui/realsr-ncnn-vulkan](https://github.com/nihui/realsr-ncnn-vulkan).