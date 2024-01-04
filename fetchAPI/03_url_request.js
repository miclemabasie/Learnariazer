// URL adn Request Objects

/*
url: href, host, hostname, port, protocol, origin, pathname, hash search, searchParams
requst options: method, body, headers, cache
cache
- 'default': cache first, server request if state, update cache if newer
- 'reload': always go to server AND update the cache
- 'no-store': always go to server but do not update the cache
- 'no-cache': make a conditional request to server and compare, update cahce and use latest
- 'force-cache': only makes reqeust if there is no HTTP cahce file
- 'only-if-cache': from cache or 504 gateway timeout errors
Headers
- string | object literal | new Headers()
*/



const str = "http://localhost:8000/api/test/"

function getData(){
    // defining a url object for fetch
    let url = new URL(str)

    // we can pass this object into the fetch function
    // fetch(url)

    // we can also construct an HTTP Response object 
    const request = new Request(url, {
        headers: {},
        method: "GET",
        cache: "no-store"
    })

    // we then pass this request object into the fetch function call
    fetch(request)
    .then(response => {
        if(!response.ok) throw new Error("Invalid response.")
        return response.json()
    })
    .then(data => {
        console.log(data)
    })
    .catch(err => {
        console.log(err)
    })
}

getData()