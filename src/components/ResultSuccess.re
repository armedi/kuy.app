[@react.component]
let make = (~link: string, ~shortLink: string, ~reset: unit => unit) => {
  let shortLink_ = "https://kuy.sh" ++ shortLink;

  <div className="w-full relative">
    <div
      className="result md:flex md:justify-between md:items-center max-w-6xl mx-auto rounded-md shadow-sm bg-white py-4">
      <span
        className="block mx-2 mb-2 md:mb-0 sm:mx-4 lg:mx-6 font-light max-w-md truncate">
        {React.string(link)}
      </span>
      <span className="block mx-2 sm:mx-4 lg:mx-6 text-indigo-600">
        <a href=shortLink_> {React.string(shortLink_)} </a>
      </span>
    </div>
    <div
      className="absolute w-full text-center text-sm"
      style={ReactDOMRe.Style.make(~bottom="-2rem", ())}>
      <span
        className="tracking-wide text-gray-100 cursor-pointer border-b border-gray-100 border-dotted"
        onClick={_ => reset()}>
        {React.string("Shorten another link")}
      </span>
    </div>
  </div>;
};
