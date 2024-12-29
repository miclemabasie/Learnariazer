import React from "react";

const PropertyCard = ({ property }) => {
  return (
    <div className="max-w-sm rounded overflow-hidden shadow-lg border border-gray-200 bg-white">
      {/* Image Section */}
      <div className="h-48 bg-gray-100 flex items-center justify-center">
        {property.images && property.images.length > 0 ? (
          <img
            className="object-cover h-full w-full"
            src={property.images[0]}
            alt={property.title}
          />
        ) : (
          <img
            className="object-cover h-full w-full"
            src="https://via.placeholder.com/300x200.png?text=No+Image"
            alt="Placeholder"
          />
        )}
      </div>

      {/* Content Section */}
      <div className="px-6 py-4">
        {/* Title */}
        <h2 className="text-lg font-bold text-gray-800 truncate">
          {property.title}
        </h2>

        {/* Location */}
        <p className="text-sm text-gray-500 mt-2">
          {property.town || "Town not available"}
        </p>

        {/* Region */}
        <p className="text-sm text-gray-600 mt-1">
          Region: <span className="font-semibold">{property.region}</span>
        </p>

        {/* Dimensions */}
        <p className="text-sm text-gray-600 mt-1">
          Dimensions:{" "}
          <span className="font-semibold">
            {property.width}m x {property.length}m
          </span>
        </p>

        {/* Price */}
        <p className="text-lg text-green-600 font-bold mt-3">
          ${parseFloat(property.price).toLocaleString()}
        </p>

        {/* Advert Type */}
        <p className="text-sm text-blue-600 font-medium mt-1">
          {property.advert_type}
        </p>
      </div>

      {/* Footer */}
      <div className="px-6 py-4 flex justify-between items-center border-t">
        {/* Owner */}
        <p className="text-sm text-gray-500">
          By: <span className="font-semibold text-gray-800">{property.owner}</span>
        </p>

        {/* Views */}
        <p className="text-sm text-gray-500">
          Views: <span className="font-semibold">{property.views}</span>
        </p>
      </div>

      {/* Call to Action */}
      <div className="px-6 py-4">
        <a
          href={property.url}
          target="_blank"
          rel="noopener noreferrer"
          className="block text-center bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600 transition duration-200"
        >
          View Property
        </a>
      </div>
    </div>
  );
};

export default PropertyCard;
