// Function to create a list of random intergers
function generate_random_ints(size) {
    let numbers = []
    for (let i = 0; i < size; i++) {
        let num = Math.round(Math.random() * size);
        if (!(num in numbers)) {
            numbers.push(num);
        }
    }
    // Clean redundant data from the array
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




let new_arr = generate_random_ints(100)
// function to show array contents
console.log("before sort", new_arr);
quick_sort(new_arr, 0, new_arr.length - 1);
console.log("After sort", new_arr);
// Function to sort the list of random intergers