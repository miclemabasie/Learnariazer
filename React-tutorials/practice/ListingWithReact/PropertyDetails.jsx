import React from "react";
import { useParams } from "react-router-dom";

const PropertyDetail = ({ properties }) => {
  const { pkid } = useParams();

  // Find the property using pkid from URL params
  const property = properties.find((property) => property.pkid === parseInt(pkid));

  if (!property) {
    return <div>Property not found</div>;
  }

  return (
    <div className="max-w-4xl mx-auto p-6 bg-white shadow-md rounded-lg">
      {/* Property Image */}
      <div className="mb-6">
        {property.images.length > 0 ? (
          <img
            className="object-cover h-96 w-full rounded-lg"
            src={property.images[0]}
            alt={property.title}
          />
        ) : (
          <img
            className="object-cover h-96 w-full rounded-lg"
            src="https://via.placeholder.com/800x600.png?text=No+Image"
            alt="Placeholder"
          />
        )}
      </div>

      <h1 className="text-3xl font-bold text-gray-800">{property.title}</h1>
      <p className="text-lg text-gray-600 mt-2">{property.description}</p>

      <div className="mt-4">
        <h2 className="text-xl font-semibold text-gray-800">Details</h2>
        <ul className="space-y-2 text-gray-600 mt-2">
          <li><strong>Location: </strong>{property.location}</li>
          <li><strong>Price: </strong>${parseFloat(property.price).toLocaleString()}</li>
          <li><strong>Advert Type: </strong>{property.advert_type}</li>
          <li><strong>Dimensions: </strong>{property.width}m x {property.length}m</li>
          <li><strong>Region: </strong>{property.region}</li>
        </ul>
      </div>

      <div className="mt-4">
        <h3 className="text-lg font-semibold text-gray-800">Owner</h3>
        <p className="text-gray-600">{property.owner}</p>
      </div>

      <div className="mt-4">
        <a
          href={property.url}
          target="_blank"
          rel="noopener noreferrer"
          className="block text-center bg-blue-500 text-white px-6 py-3 rounded-lg hover:bg-blue-600"
        >
          Visit Property URL
        </a>
      </div>
    </div>
  );
};

export default PropertyDetail;
