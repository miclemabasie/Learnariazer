import InputBox from "./components/InputBox";
import { useState } from "react";
import useCurrencyInfo from "./hooks/UseCurrencyInfo";  // Custom hook for fetching currency info
import useCurrencyConversion from "./hooks/useCurrencyConversion";  // Hook for converting currencies

export default function App() {
    const [fromCurrency, setFromCurrency] = useState("USD");
    const [toCurrency, setToCurrency] = useState("EUR");
    const [amount, setAmount] = useState(1);
    const [currencyDisabled, setCurrencyDisabled] = useState(false)
  
    const currencyData = useCurrencyInfo('currency');
    const options = currencyData?.currencies ? Object.keys(currencyData.currencies) : [];

    // Use custom hook for currency conversion
    const { conversionResult, error, loading } = useCurrencyConversion(fromCurrency, toCurrency, amount);

    const handleToCurrencyChange = (e) => {
        setToCurrency(e);  // Update the target currency
        // Consider triggering a re-fetch here if necessary
    };
    const disableToCurrency = () => {
      setCurrencyDisabled(prev => !prev); // Toggle the value
    };
  

    return (
        <div className="w-full h-screen flex flex-wrap justify-center items-center bg-cover bg-no-repeat"
            style={{ backgroundImage: `url(https://images.pexels.com/photos/210600/pexels-photo-210600.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1)` }}
        >
            <div className="w-200 bg-gray-400 text-white rounded-lg p-5">
                <InputBox 
                    label='From' 
                    boxTitle='Currency Type' 
                    id='fromCurrency'
                    currencOptions={options}
                    selectedCurrency={fromCurrency}
                    amount={amount}
                    onAmountChange={(amount) => setAmount(amount)}
                    onCurrencyChange={(currency) => {
                        setFromCurrency(currency);
                    }}
                    amoundDisabled={false}
                    currencyDisabled={false}
                />
                
                <InputBox 
                    label='To' 
                    boxTitle='Currency Type' 
                    id='toCurrency'
                    currencOptions={options}
                    selectedCurrency={toCurrency}
                    onCurrencyChange={handleToCurrencyChange} // Set up the handler
                    amoundDisabled={true}
                    currencyDisabled={currencyDisabled}
                />

                {/* Display conversion result */}
                <div className="mt-4">
                    {loading ? (
                        <p>Loading conversion...</p>
                    ) : error ? (
                        <p>Error: {error}</p>
                    ) : (
                        conversionResult && conversionResult.rates && conversionResult.rates[toCurrency] ? (
                            <p>
                                {amount} {fromCurrency} = {conversionResult.rates[toCurrency].rate_for_amount} {toCurrency}
                            </p>
                        ) : (
                            <p>No conversion rate available for {toCurrency}.</p>
                        )
                    )}
                </div>

            <input type="checkbox"
              onChange={(e) => {
                disableToCurrency();
              }}
            />
            </div>
        </div>
    );
}
