import { useEffect, useState } from "react";

function useCurrencyInfo(currency) {
    const [data, setData] = useState({});
    
    useEffect(() => {
        const fetchData = async () => {
            const options = {
                method: 'GET',
                headers: {
                    'x-rapidapi-host': 'currency-converter5.p.rapidapi.com',
                    'x-rapidapi-key': 'e77062eb91msh4dde1a91ecc4f2cp11902djsn277f35de9bd9'
                }
            };

            try {
                const response = await fetch(`https://currency-converter5.p.rapidapi.com/currency/list?format=json&language=en`, options);
                if (!response.ok) {
                    throw new Error("Network response was not ok");
                }
                const result = await response.json();
                setData(result);
            } catch (error) {
                console.error("There was a problem with the fetch request:", error);
            }
        };

        fetchData();
    }, [currency]);

    // Return the data to be used in the component
    return data;
}

export default useCurrencyInfo;
