let url = "http://localhost:8000/api/v1/orders/"

let head = document.getElementById("heading")

head.style.display = "none"

function getData(url) {
    fetch(url)
    .then(response => {
        if(!response.ok) throw new Error("Invalid response!")
        return response.json();
    })
    .then(data => {
        console.log(data)
        let ordersElement = document.getElementById("orders")
        console.log(ordersElement)
        data.orders.forEach(order => {     
            if(order.validated) {   
            let elem = `<h1>transaction ID:  ${order.transaction_id}</h1>
            <a href="${url}${order.transaction_id}"> see order </a>`
            ordersElement.innerHTML += elem;
        }
        });
    })
    .catch(err => {
        console.log(err)
    })
}


getData(url)