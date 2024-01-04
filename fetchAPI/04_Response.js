

let obj = {
    id: crypto.randomUUID(),
    name: "Mans Clot",
    favouriteColor: "blue"
};


function getData() {
    let jsonString = JSON.stringify(obj)
    console.log(jsonString)

    let file = new File([jsonString], "data.json", {type: "application/json"})
    
    let response = new Response(file, {
        headers: {
            "centent-type": "application/json",
            "content-length": file.size,
            "X-miclem": "Abasie",
        },
    })

    console.log(response)
    console.log("content-type", response.headers.get("content-type"))
    console.log("content-legth", response.headers.get("content-length"))
    console.log("X-miclem", response.headers.get("X-miclem"))


    console.log(response.body)
    
}


getData()