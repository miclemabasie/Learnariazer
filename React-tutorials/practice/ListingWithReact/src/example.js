import React, { useEffect, useState } from "react";

const PropertyList = () => {
  const [properties, setProperties] = useState([]); // State to hold the list of properties
  const [error, setError] = useState(null); // State to handle errors
  const [loading, setLoading] = useState(true); // State to show loading

  useEffect(() => {
    // Fetch data from the backend API
    fetch("http://localhost:8000/api/properties") // Replace with your backend URL
      .then((response) => {
        if (!response.ok) {
          throw new Error("Failed to fetch properties");
        }
        return response.json();
      })
      .then((data) => {
        setProperties(data); // Set the fetched properties
        setLoading(false); // Loading is complete
      })
      .catch((err) => {
        setError(err.message); // Handle errors
        setLoading(false);
      });
  }, []);

  // Handle loading state
  if (loading) {
    return <div>Loading...</div>;
  }

  // Handle error state
  if (error) {
    return <div>Error: {error}</div>;
  }

  return (
    <div>
      <h1>Property List</h1>
      <ul>
        {properties.map((property) => (
          <li key={property.id}>Title: {property.pkid}</li> // Display property names
        ))}
      </ul>
    </div>
  );
};

export default PropertyList;
