import merge from "lodash/merge";
import { PartialDeep } from "type-fest";

import { postLink } from "@/api";
import { State } from "./types";

export const reset = (state: State) => () => {
  state.show = "input";
  state.loading = false;
  delete state.result;
  delete state.error;
};

export const submitLink = (state: State) => async (link: string) => {
  state.loading = true;

  try {
    const response = await postLink(link);
    if (response.success && response.data) {
      merge<State, PartialDeep<State>>(state, {
        show: "result",
        loading: false,
        result: {
          link: link,
          shortLink: response.data.shortLink
        }
      });
    } else {
      throw new Error(response.message);
    }
  } catch (error) {
    merge<State, PartialDeep<State>>(state, {
      show: "result",
      loading: false,
      error: error.message
    });
  }
};
