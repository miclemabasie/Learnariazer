// Using async and await istead of chaining then()
// still needs error handling with try catch


let url = "http://localhost:8000/api/v1/customers/"
async function getData() {
    // Regular
    // fetch().then().then().catch()
    try{
        let res = await fetch(url)
        let jsondata = await res.json()
        console.log(jsondata)
    } catch (err) {
        console.log(err.message)
    }
}

getData()