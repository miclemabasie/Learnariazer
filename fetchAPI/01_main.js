let url = "http://localhost:8000/api/v1/customers/"
fetch(url)
  .then((response) => {
    if(!response.ok) throw Error("invalid response!")
    console.log("response", response)
    return response.json(); // extract json sting and convert to an object
  })
  .then((data) => {
    console.log(typeof(data))
    console.log(data);
  })
  .catch((err) => {
    console.log({ error: err });
  });



// let res = fetch(url)
// .then(data => data.json())
// .then(data => console.log(data))
// .catch(error => {
//     console.log({"error": error})
// })

// console.log(res)