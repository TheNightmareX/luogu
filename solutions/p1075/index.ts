function isFactor(n1: number, n2: number) {
  return n2 % n1 == 0;
}

function isPrime(n: number) {
  for (let cur = 2; cur <= n ** (1 / 2); cur++) {
    if (n % cur == 0) return false;
  }
  return true;
}

async function main() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const input: number = await new Promise((r) =>
    process.stdin.once("data", (raw: string) => r(parseInt(raw)))
  );

  let minPrimeFactor: number;
  for (let cur = 2; cur <= input ** (1 / 2); cur++) {
    if (isFactor(cur, input) && isPrime(cur)) {
      minPrimeFactor = cur;
      break;
    }
  }

  const maxPrimeFactor = input / minPrimeFactor!;

  console.log(maxPrimeFactor);
}

main();

export {};
