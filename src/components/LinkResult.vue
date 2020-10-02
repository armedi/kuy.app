<template>
  <section class="flex items-center justify-center p-6 sm:p-8 lg:p-10">
    <LinkResultError v-if="!!error" :error="error" v-bind="$attrs" />
    <LinkResultSuccess v-else :result="result" v-bind="$attrs" />
  </section>
</template>

<script lang="ts">
import { defineComponent, PropType } from "vue";

import LinkResultError from "./LinkResultError.vue";
import LinkResultSuccess from "./LinkResultSuccess.vue";

export default defineComponent({
  name: "LinkResult",
  components: {
    LinkResultError,
    LinkResultSuccess
  },
  props: {
    result: Object as PropType<{ link: string; shortLink: string }>,
    error: String
  }
});
</script>

<style scoped>
section {
  min-height: 11rem;
  background-color: #0d1836;
}
</style>
