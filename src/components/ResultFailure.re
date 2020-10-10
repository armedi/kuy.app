[@react.component]
let make = (~message: string, ~reset: unit => unit) => {
  <div className="w-full max-w-6xl mx-auto">
    <div className="text-white font-light text-center mb-8">
      {React.string(message)}
    </div>
    <div className="text-center">
      <span
        className="tracking-wide text-gray-100 cursor-pointer border-b border-gray-100 border-dotted"
        onClick={_ => reset()}>
        {React.string("Try again")}
      </span>
    </div>
  </div>;
};
