origin_path="$PWD"
dir="build_an"

mkdir "$dir"
cmake -B"$origin_path/$dir/" -S"$origin_path"

cd "$dir/"
make

cd ".."
"./$dir/bscene" > img.ppm

rm -r "$dir/";
