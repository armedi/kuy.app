import { reactive, readonly } from "vue";
import { ReadonlyDeep } from "type-fest";

import { State, Actions } from "./types";
import { submitLink, reset } from "./actions";

export const useState = (): [ReadonlyDeep<State>, Actions] => {
  const state = reactive<State>({
    show: "input",
    loading: false
  });

  return [
    readonly(state) as ReadonlyDeep<State>,
    {
      reset: reset(state),
      submitLink: submitLink(state)
    }
  ];
};
