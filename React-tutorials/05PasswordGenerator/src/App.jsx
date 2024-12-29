import { useState, useCallback, useEffect, useRef} from 'react'

function App() {
  const [len, setLen] = useState(8);
  const [numbersAllowed, setNumbersAllowed] = useState(false)
  const [charAllowed, setCharAllowed] = useState(false)
  const [password, setPassword] = useState('')
  const [btnText, setBtnText] = useState('copy')

  const passwordRef = useRef(null)

  const generatePassword = useCallback(() => {
    let pass = '';
    // Separate variables for each type of character
    let letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz';
    let numbers = '0123456789';
    let specialChars = '!@#$%^&*()_+~`|}{[]:;?><,./-=';



    // Combine all character sets
    if(numbersAllowed) letters += specialChars;
    if(numbersAllowed) letters += numbers;
    

    // Generate the password by picking random characters
    for (let i = 0; i < len; i++) {
        pass += letters.charAt(Math.floor(Math.random() * letters.length));
    }

    setPassword(pass);
  }, [len, numbersAllowed, charAllowed]);

  useEffect(() => {
    generatePassword();
  },[len, numbersAllowed, charAllowed])

  const copyPasswordToClipBoard = () => {
    window.navigator.clipboard.writeText(password);
    setBtnText('copied!')
    setTimeout(() => {
      setBtnText('copy')
    }, 2000);
  }
  return (
    <div className="w-full max-w-md mx-auto shadow-md rounded-lg px-4 py-3 my-8 bg-gray-800 text-orange-500">
      <h1 className="text-3xl font-bold mb-2 text-center">
        Password Generator
      </h1>
      <div className="flex shadow rounded-lg overflow-hidden">
        <input 
        className='outline-none w-full py-1 px-3'
        type="text" 
        placeholder='Password'
        value={password}
        readOnly
        ref={passwordRef}
        />
        <button className="outline-none bg-blue-700 text-white px-3 py-0 5 shrink-0"
        onClick={() => {copyPasswordToClipBoard()}}
        >{btnText}</button>
      </div>

      <div className="flex text-sm gap-x-2">
        <div className="flex items-center gap-x-1 mt-8">
          <input 
            type="range"
            min={8}
            max={32}
            value={len} 
            className='cursor-pointer'
            onChange={(e) => {setLen(e.target.value)}}
          />
          <label htmlFor="lenght">Length: {len}</label>
        </div>

        <div className="flex items-center gap-x-1 mt-8">
          <input
          type='checkbox'
          checked={numbersAllowed}
          onChange={() => {
            setNumbersAllowed((prev) => !prev)
          }}
          />
          <label htmlFor="number">Number</label>
        </div>

        <div className="flex items-center gap-x-1 mt-8">
          <input
          type='checkbox'
          checked={charAllowed}
          onChange={() => {
            setCharAllowed((prev) => !prev)
          }}
          />
          <label htmlFor="chat">Char</label>
        </div>
      </div>
    </div>
  )
}

export default App
