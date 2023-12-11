function merge_sort(arr) {
    if (arr.length < 2) {
        return arr;
    }
    // slit the array into 2 halfs
    const middleIndex = Math.floor(arr.length / 2)
    const leftArr = arr.slice(0, middleIndex)
    const rightArr = arr.slice(middleIndex, arr.length)

    return merge(merge_sort(leftArr), merge_sort(rightArr))

}

function merge(leftArr, rightArr) {
    let resultArr = []
    let leftIndex = 0;
    let rightIndex = 0;

    while (leftIndex < leftArr.length && rightIndex < rightArr.length) {
        if (leftArr[leftIndex] < rightArr[rightIndex]) {
            resultArr.push(leftArr[leftIndex])
            leftIndex += 1;
        } else {
            resultArr.push(rightArr[rightIndex])
            rightIndex += 1;
        }
    }
    return resultArr.concat(leftArr.slice(leftIndex)).concat(rightArr.slice(rightIndex))
}

list = [2, 1, 8, 7, 3]

console.log(merge_sort(list))