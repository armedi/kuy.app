open Belt;

let apiUrl = "https://kuy.sh";

module Decode = {
  type data = {shortLink: string};
  type submitLinkApiResponse = {
    success: bool,
    data: option(data),
    message: option(string),
  };

  let data = json =>
    Json.Decode.{shortLink: json |> field("shortLink", string)};

  let submitLinkApiResponse = json =>
    Json.Decode.{
      success: json |> field("success", bool),
      data: json |> optional(field("data", data)),
      message: json |> optional(field("message", string)),
    };
};

type submitLinkResponse = Result.t(Decode.data, string);

let submitLink = (link: string): Js.Promise.t(submitLinkResponse) => {
  let unexpectedErrorMessage = "Something went wrong!";
  let payload = Json.Encode.(object_([("link", string(link))]));

  Fetch.fetchWithInit(
    apiUrl,
    Fetch.RequestInit.make(
      ~method_=Fetch.Post,
      ~body=payload->Json.stringify->Fetch.BodyInit.make,
      (),
    ),
  )
  |> Js.Promise.then_(Fetch.Response.json)
  |> Js.Promise.then_(json => {
       let decoded = json->Decode.submitLinkApiResponse;
       decoded.success
         ? {
           switch (decoded.data) {
           | Some(data) => Js.Promise.resolve(Result.Ok(data))
           | None => Js.Promise.resolve(Result.Error(unexpectedErrorMessage))
           };
         }
         : Js.Promise.resolve(
             Result.Error(
               Option.getWithDefault(decoded.message, unexpectedErrorMessage),
             ),
           );
     })
  |> Js.Promise.catch(_ =>
       Js.Promise.resolve(Result.Error(unexpectedErrorMessage))
     );
};
