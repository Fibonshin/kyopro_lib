N="${3:-30}"

mkdir -p test
g++ "$1".cpp -o test/main
g++ "$2".cpp -o test/naive

ok=true

for ((i=1; i<=N; i++)); do
  python3 test/generate.py > test/in
  ./test/main < test/in > test/out1.txt
  ./test/naive < test/in > test/out2.txt
  if ! diff test/out1.txt test/out2.txt; then
    echo "found at test #$i"
	ok=false
    break
  fi
done

if $ok; then
	echo "All $N tests passed!"
fi

rm test/main test/naive
