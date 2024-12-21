# Image
```shell
./realesrgan-ncnn-vulkan -i input.jpg -o output.png
```
```shell
./realesrgan-ncnn-vulkan -i input.jpg -o output.png -n realesr-animevideov3
```
```shell
./realesrgan-ncnn-vulkan -i input_folder -o outputfolder -n realesr-animevideov3 -s 2 -f jpg
```
```shell
./realesrgan-ncnn-vulkan -i input_folder -o outputfolder -n realesr-animevideov3 -s 4 -f jpg
```

# Video

1. Use ffmpeg to extract frames from a video (Remember to create the folder `tmp_frames` ahead)

```shell
ffmpeg -i onepiece_demo.mp4 -qscale:v 1 -qmin 1 -qmax 1 -vsync 0 tmp_frames/frame%08d.jpg
```

2. Inference with Real-ESRGAN executable file (Remember to create the folder `out_frames` ahead)

```shell
./realesrgan-ncnn-vulkan -i tmp_frames -o out_frames -n realesr-animevideov3 -s 2 -f jpg
```

3. Merge the enhanced frames back into a video

```
ffmpeg -i out_frames/frame%08d.jpg -i onepiece_demo.mp4 -map 0:v:0 -map 1:a:0 -c:a copy -c:v libx264 -r 23.98 -pix_fmt yuv420p output_w_audio.mp4
```
