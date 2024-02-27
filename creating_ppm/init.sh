path="$PWD/main.cpp"
bin="gradient"

if [ -f "$path" ]
then
    g++ "main.cpp" "-o" "$bin"
    ./gradient > "img.ppm"
    rm "$bin"
else
    echo "main.cpp not found"
fi

