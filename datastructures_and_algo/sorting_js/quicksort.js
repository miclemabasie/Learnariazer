// Function to create a list of random intergers
function generate_random_ints() {
    let numbers = [];
    for (let i = 0; i < 100; i++) {
        numbers.push(Math.round(Math.random() * 100));
    }
    return numbers;
}

function quick_sort(arr, start, end) {
    if (start < end) {
        // Get the index of the mid pivot
        pivot = partition(arr, start, end);
        // Sort the left side of the pivot
        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}




function partition(arr, start, end) {
    let pivot = arr[end];
    let p_index = start;
    let i = start;
    for (i; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(arr, i, p_index);
            p_index++;
        }

    }
    swap(arr, p_index, i);
    return p_index;
}

function swap(arr, i, j) {
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


// let arr = generate_random_ints();
let arr = [7, 2, 1, 6, 8, 5, 3, 4]

// function to show array contents
console.log("before sort", arr);
quick_sort(arr, 0, 7);
console.log("After sort", arr);
// Function to sort the list of random intergers