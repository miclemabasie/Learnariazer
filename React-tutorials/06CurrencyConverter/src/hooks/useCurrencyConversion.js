import { useEffect, useState } from "react";

function useCurrencyConversion(fromCurrency, toCurrency, amount) {
    const [conversionResult, setConversionResult] = useState(null);
    const [error, setError] = useState(null);
    const [loading, setLoading] = useState(true); // For tracking loading state
    console.log("these are the value", fromCurrency, toCurrency, amount)
    useEffect(() => {
        const fetchData = async () => {
            const url = `https://currency-converter5.p.rapidapi.com/currency/convert?format=json&from=${fromCurrency}&to=${toCurrency}&amount=${amount}&language=en`;
            const options = {
                method: 'GET',
                headers: {
                    'x-rapidapi-key': 'e77062eb91msh4dde1a91ecc4f2cp11902djsn277f35de9bd9',
                    'x-rapidapi-host': 'currency-converter5.p.rapidapi.com'
                }
            };

            try {
                setLoading(true); // Start loading
                const response = await fetch(url, options);
                if (!response.ok) {
                    throw new Error("Network response was not ok");
                }
                const result = await response.json();
                setConversionResult(result);
            } catch (err) {
                setError(err.message);
            } finally {
                setLoading(false); // End loading
            }
        };

        fetchData();
    }, [fromCurrency, toCurrency, amount]); // Re-run when these parameters change
    console.log('resutls', conversionResult)
    return { conversionResult, error, loading };
}

export default useCurrencyConversion;
