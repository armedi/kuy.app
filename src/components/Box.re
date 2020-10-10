[@react.component]
let make = (~children, ()) => {
  <section
    className="flex items-center p-6 sm:p-8 lg:p-10"
    style={ReactDOMRe.Style.make(
      ~minHeight="11rem",
      ~backgroundColor="#0d1836",
      (),
    )}>
    children
  </section>;
};
