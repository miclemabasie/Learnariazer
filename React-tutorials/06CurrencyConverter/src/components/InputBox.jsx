import React from 'react'

function InputBox({label, boxTitle, amount, onAmountChange, onCurrencyChange, currencOptions=[], selectedCurrency="usd", amoundDisabled=false, currencyDisabled=false, className="", id,}) {
  return (
    <div className='bg-white text-black rounded-lg m-5 p-6 flex flex-col justify-between'
    >
        <div className="text-gray-400 flex flex-row justify-between">
            <label htmlFor={id} className='pr-96 pb-10'>{label}</label>
            <h1>{boxTitle}</h1>
        </div>
        <div className="flex flex-row justify-between">
            <input type="number" 
                id={id}
                className='outline-4 w-1/2 bg-transparent pl-2'
                placeholder='Amount'
                disabled={amoundDisabled}
                value={amount}
                onChange={(e) => {
                    console.log(e.target.value)
                    onAmountChange && onAmountChange(Number(e.target.value))
                }}
            />
            <select className='px-5 py-2 rounded-md' 
                name="currency" 
                value={selectedCurrency}
                disabled={currencyDisabled}
                onChange={(e) => {onCurrencyChange && onCurrencyChange(e.target.value)}}
                >

                {currencOptions.map((currency) => (
                    <option key={currency} value={currency}>{currency }</option>
                ))}
            </select>
        </div> 
    </div>
  )
}

export default InputBox