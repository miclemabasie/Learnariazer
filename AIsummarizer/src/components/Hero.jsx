import { logo } from "../assets"


const Hero = () => {
  return (
    <header className="w-full flex justify-center items-center flex-col">
        <nav className="flex justify-between w-full items-center  mb-10 pt-3 ">
            <img src={logo} alt="sums_logo" className="w-28 object-contain" />

            <button
                type="button"
                onClick={() => window.open("https://github.com/miclemabasie/")}
                className="black_btn"
            >Github</button>
        </nav>

        <h1 className="head_text">
            Summarize Articles with <br className="max-md:hidden"/>
            <span className="orange_gradient">OpenAI GPT-4</span>
        </h1>
        <h2 flex="desc">
            Simplify your reading with summize, an open-source article summarizer that transforms lengthy articles into clear and consise summaries
        </h2>
    </header>
  )
}

export default Hero