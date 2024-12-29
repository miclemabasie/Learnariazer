
// const urlw = `https://currency-converter18.p.rapidapi.com/api/v1/convert?from=${from}&to=${to}&amount=100`;

let from = "EUR"
let to = "XAF"

const url = 'https://currency-converter18.p.rapidapi.com/api/v1/supportedCurrencies';

console.log(url)

const options = {
    method: 'GET',
    headers: {
        'X-RapidAPI-Key': 'e77062eb91msh4dde1a91ecc4f2cp11902djsn277f35de9bd9',
        'X-RapidAPI-Host': 'currency-converter18.p.rapidapi.com'
    }
};

let d = document.getElementById("data")

fetch(url, options)
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json()
    })
    .then(data => {
        data.forEach(element => {
            let i = `${element.symbol}`;
            d.append(i)
            console.log(element.name)
        });
    })
    .catch(error => {
        // Handle errors
        console.error('Fetch error:', error);
    });