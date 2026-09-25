DIR=debug
N="${3:-1000}"

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
	pypy3 ${DIR}/generate.py > ${DIR}/in
	./${DIR}/main < ${DIR}/in > ${DIR}/wa.txt
	./${DIR}/naive < ${DIR}/in > ${DIR}/ac.txt
	if ! diff -q ${DIR}/wa.txt ${DIR}/ac.txt > /dev/null; then
		echo
		echo "Found at test #$i"
		echo
		echo "[Input]"
		cat ${DIR}/in
		echo
		echo -e "\033[31m[WA]\033[0m"
		cat ${DIR}/wa.txt
		echo
		echo -e "\033[32m[AC]\033[0m"
		cat ${DIR}/ac.txt
		echo

		ok=false
		break
	fi
done

if $ok; then
	echo "All $N tests passed!"
fi

rm ${DIR}/main ${DIR}/naive
