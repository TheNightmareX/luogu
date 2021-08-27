/**
 * 最大公约数：欧几里得
 */
function euclidean(numA: number, numB: number): number {
  return !numB ? numA : euclidean(numB, numA % numB);
}
