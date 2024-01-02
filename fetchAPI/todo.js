// Mastering the FetchAPI

/** 
1. fetch(string | url | request)
Promises
.then().then().catch()

2. async await + try catch

3. new URL()
url.hre, host, hostname, port, protocol, orgin, pathname, hash, search, seachParams
new Request(strin | url, options)
Haders - https//developer.mozilla.org/en-US/docs/Web/HTTP/Headers

4. new Response(strin | url | request, File | Blog, options)
HTTP Methods
GET - reading one or more resources (no body)
POST - create new resource (has body)
PUT - replace an existing resource (has body)
PATCH - edit part of an existing resource (has body)
DELETE - delete an existing resource
OPTIONS - preflight request CORS
HEAD - just get the header for a Response
Body - from inside Response object
body.text()
body.json()
body.blob()

5. generating html from response data array
generating image from response blob

6. API keys - custom header, authorization header, querystring
new URLSearchParams(string | formData | iterable Object)
urlsearchparams.append(nae, value)
Authorization header
content-type header
forbiddend header names
custom x- header
Content-Security-Policy connect-src

7. Uploading data
new Formdata(FormElement) ?
formdata.append(name, value)
formdata.append(name, blob, filename)
body: Object literal or string or Blob or attatchment(s)
header content-disposition: multipart/form-data;boundary-asdf from Formdata

8. CORS concepts 
simple request
request mode: "cors", "no-cors", *cors, same-origin
request credentials: "same-origin", - include, *same-origin, omit
request cache: "no-chache", - *default, no-cache, reload, force-cache, only-if-cached
access-control-allow-arogin
access-control-allow-method

9. Handling multiple fetch calls with Promiss.all() .race() .allSettled()

12. Aborting a fet h reqeust with an AbortController
=> Measuring download time of resource

*/
