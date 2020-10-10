open Belt;

type result = {
  link: string,
  shortLink: string,
};

type message = string;

type state =
  | Idle
  | Submitting
  | Success(result)
  | Failure(message);

type action =
  | Reset
  | SetSubmitting
  | SetSuccess(result)
  | SetFailure(message);

let reducer = (_: state, action: action): state => {
  switch (action) {
  | Reset => Idle
  | SetSubmitting => Submitting
  | SetSuccess(result) => Success(result)
  | SetFailure(message) => Failure(message)
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, Idle);

  let reset = () => dispatch(Reset);

  let submitLink = (link: string) => {
    dispatch(SetSubmitting);

    Api.submitLink(link)
    |> Js.Promise.then_((response: Api.submitLinkResponse) =>
         switch (response) {
         | Result.Ok({shortLink}) =>
           dispatch(SetSuccess({link, shortLink})) |> Js.Promise.resolve
         | Result.Error(message) =>
           dispatch(SetFailure(message)) |> Js.Promise.resolve
         }
       )
    |> ignore;
  };

  <>
    <Hero />
    <Box>
      {switch (state) {
       | Idle => <LinkInput submitLink />
       | Submitting => <LinkInput submitLink loading=true />
       | Success({link, shortLink}) => <ResultSuccess link shortLink reset />
       | Failure(message) => <ResultFailure message reset />
       }}
    </Box>
  </>;
};
