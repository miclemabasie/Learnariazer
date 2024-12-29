
import React, {useState, useEffect} from "react";
import PropertyCard from "./PropertyCard";

const PropertyList = () => {
    const [properties, setProperties] = useState([]);
    const [error, setError] = useState(null)
    const [loading, setLoading] = useState(true)


    useEffect(() => {
        // fecth data from the backend api
        const url = `http://localhost/api/v1/properties/homes/`
        fetch(url)
        .then((response) => {
            if(!response.ok) {
                throw new Error("Failed to fetch properties");
            }
            return response.json();
        })
        .then((data) => {
            console.log(data.results)
            setProperties(data.results); // Set the fetched properties
            setLoading(false); // Loading is complete
        })
        .catch((err) => {
            setError(err.message);
            setLoading(false)
        })
    }, [])

    if(loading) {
        return <div>Loading...</div>
    }

    if(error){
        return <div>Error: {error}</div>
    }

    return (
        <ul className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6">
          {properties.map((property) => (
            <li key={property.id}>
              <PropertyCard property={property} />
            </li>
          ))}
        </ul>
      );
}

export default PropertyList