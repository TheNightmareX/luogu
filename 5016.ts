async function parseInput() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const input: number[][] = await new Promise((resolve) =>
    process.stdin.on("data", (raw: string) =>
      resolve(
        raw
          .trim()
          .split("\n")
          .map((line) => line.split(" ").map((s) => parseFloat(s)))
      )
    )
  );
  return input;
}

async function main() {
  let [
    ,
    soldierCountMap,
    [
      middleSoldierGroupIndex,
      enhancedSoldierGroupIndex,
      additionalSoldiers,
      ownSolders,
    ],
  ] = await parseInput();
  middleSoldierGroupIndex--;
  enhancedSoldierGroupIndex--;
  soldierCountMap[enhancedSoldierGroupIndex] += additionalSoldiers;
  //   console.debug(`兵营： ${soldierCountMap}`);
  //   console.debug(`场外工兵：${ownSolders}`);

  let totalPowerOfA = 0;
  let totalPowerOfB = 0;
  for (let index = 0; index < soldierCountMap.length; index++) {
    const power =
      soldierCountMap[index] * Math.abs(middleSoldierGroupIndex - index);
    if (index < middleSoldierGroupIndex) totalPowerOfA += power;
    if (index > middleSoldierGroupIndex) totalPowerOfB += power;
  }
  //   console.debug(`A势力： ${totalPowerOfA} B势力：${totalPowerOfB}`);

  /**
   * positive: A
   * negative: B
   */
  const powerGap = totalPowerOfA - totalPowerOfB;
  //   console.debug(`势力差距： ${powerGap}`);

  let bestSoldierGroupIndex = 0;
  let bestPowerEffect = 0;
  for (let index = 0; index < soldierCountMap.length; index--) {
    const powerEffect = ownSolders * (middleSoldierGroupIndex - index);
    // console.debug(`兵营编号：${index}`, `势力影响： ${powerEffect}`);
    if (
      Math.abs(powerGap + powerEffect) < Math.abs(powerGap + bestPowerEffect)
    ) {
      bestSoldierGroupIndex = index;
      bestPowerEffect = powerEffect;
    }
  }

  console.log(bestSoldierGroupIndex + 1);
}

main();

export {};
