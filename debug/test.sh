DIR=debug
N="${3:-30}"

if [[ -z "$1" || -z "$2" ]]; then
    echo "Usage: $0 <main> <naive> [N]"
    exit 1
fi

mkdir -p ${DIR}
g++ "$1".cpp -o ${DIR}/main
g++ "$2".cpp -o ${DIR}/naive

ok=true

for ((i=1; i<=N; i++)); do
  echo -ne "\rRunning test $i/$N..."
  python3 ${DIR}/generate.py > ${DIR}/in
  ./${DIR}/main < ${DIR}/in > ${DIR}/out1.txt
  ./${DIR}/naive < ${DIR}/in > ${DIR}/out2.txt
  if ! diff ${DIR}/out1.txt ${DIR}/out2.txt; then
    echo "found at test #$i"
	ok=false
    break
  fi
done

if $ok; then
	echo "All $N tests passed!"
fi

rm ${DIR}/main ${DIR}/naive
