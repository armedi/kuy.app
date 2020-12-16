module Styles = {
  let inputAndButton =
    ReactDOMRe.Style.make(~height="3.125rem", ~minWidth="10rem", ());
};

[@react.component]
let make = (~submitLink: string => unit, ~loading: bool=false, ()) => {
  let (input, setInput) = React.useState(() => "");

  let handleInputChange = event => {
    let value = event->ReactEvent.Form.target##value;
    setInput(_ => value);
  };

  let handleSubmit = event => {
    ReactEvent.Form.preventDefault(event);
    submitLink(input);
  };

  <form
    className="md:flex w-full max-w-6xl md:mx-auto"
    autoComplete="off"
    onSubmit=handleSubmit>
    <div className="md:flex-grow">
      <label htmlFor="link" className="sr-only">
        {React.string("link")}
      </label>
      <div className="relative rounded-md shadow-sm">
        <input
          id="link"
          className="form-input block w-full py-3 text-base leading-6 sm:leading-5"
          style=Styles.inputAndButton
          placeholder="Shorten your link"
          value=input
          onChange=handleInputChange
        />
      </div>
    </div>
    <span className="block rounded-md shadow-sm mt-2 md:mt-0 md:ml-4 lg:ml-6">
      <button
        type_="submit"
        className="inline-flex items-center justify-center w-full py-3 border border-transparent text-base leading-6 rounded-md text-white bg-indigo-600 hover:bg-indigo-500 focus:outline-none focus:border-indigo-700 focus:shadow-outline-indigo active:bg-indigo-700 disabled:bg-indigo-200 disabled:cursor-not-allowed transition ease-in-out duration-150"
        style=Styles.inputAndButton
        disabled=loading>
        {loading
           ? <span
               className="animate-spin h-7 w-7 border-4 border-indigo-400 rounded-full"
               style={ReactDOMRe.Style.make(~borderTopColor="#f0f5ff", ())}
             />
           : <span className="tracking-wider">
               {React.string("Shorten")}
             </span>}
      </button>
    </span>
  </form>;
};
