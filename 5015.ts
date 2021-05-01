async function main() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const content: string = await new Promise((r) =>
    process.stdin.once("data", r)
  );
  console.log(content.replace(/[ \r\n]/g, "").length);
}

main();
