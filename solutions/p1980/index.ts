async function main() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const [top, target]: number[] = await new Promise((r) =>
    process.stdin.once("data", (raw: string) =>
      r(
        raw
          .trim()
          .split(" ")
          .map((v) => +v)
      )
    )
  );

  const strTarget = String(target);

  let ans = 0;

  for (let cur = 1; cur <= top; cur++) {
    const str = String(cur);
    str.split("").forEach((s) => {
      if (s == strTarget) ans++;
    });
  }

  console.log(ans);
}

main();

export {};
